# Edit this configuration file to define what should be installed on
# your system.  Help is available in the configuration.nix(5) man page
# and in the NixOS manual (accessible by running ‘nixos-help’).

{ config, pkgs, ... }:

{
  imports =
    [ # Include the results of the hardware scan.
      ./hardware-configuration.nix
    ];

  # Bootloader.
  boot.loader.systemd-boot.enable = true;
  boot.loader.efi.canTouchEfiVariables = true;

  networking.hostName = "nixos"; # Define your hostname.
  # networking.wireless.enable = true;  # Enables wireless support via wpa_supplicant.

  # Configure network proxy if necessary
  # networking.proxy.default = "http://user:password@proxy:port/";
  # networking.proxy.noProxy = "127.0.0.1,localhost,internal.domain";

  # Enable networking
  networking.networkmanager.enable = true;

  # Set your time zone.
  time.timeZone = "Europe/Skopje";

  # Select internationalisation properties.
  i18n.defaultLocale = "en_US.UTF-8";

  i18n.extraLocaleSettings = {
    LC_ADDRESS = "mk_MK.UTF-8";
    LC_IDENTIFICATION = "mk_MK.UTF-8";
    LC_MEASUREMENT = "mk_MK.UTF-8";
    LC_MONETARY = "mk_MK.UTF-8";
    LC_NAME = "mk_MK.UTF-8";
    LC_NUMERIC = "mk_MK.UTF-8";
    LC_PAPER = "mk_MK.UTF-8";
    LC_TELEPHONE = "mk_MK.UTF-8";
    LC_TIME = "mk_MK.UTF-8";
  };

  # Enable the X11 windowing system.
  # You can disable this if you're only using the Wayland session.
  services.xserver.enable = true;

  # Enable the KDE Plasma Desktop Environment.
  services.displayManager.sddm.enable = true;
  services.desktopManager.plasma6.enable = true;
  programs.hyprland.enable = true;

  # Configure keymap in X11
  services.xserver.xkb = {
    layout = "us";
    variant = "";
  };

  # Enable CUPS to print documents.
  services.printing.enable = true;

  # Enable sound with pipewire.
  services.pulseaudio.enable = false;
  security.rtkit.enable = true;
  services.pipewire = {
    enable = true;
    alsa.enable = true;
    alsa.support32Bit = true;
    pulse.enable = true;
    # If you want to use JACK applications, uncomment this
    #jack.enable = true;

    # use the example session manager (no others are packaged yet so this is enabled by default,
    # no need to redefine it in your config for now)
    #media-session.enable = true;
  };

  services.jupyter = {
    enable = true;
    ip = "127.0.0.1";
    port = 8888;
    password = "''";
    kernels = {
      python3 = let
        env = pkgs.python3.withPackages (ps: with ps; [
	  ipykernel
	  numpy
	  pandas
	  matplotlib
	]);
      in {
        displayName = "Python 3";
	argv = [ "${env}/bin/python" "-m" "ipykernel_launcher" "-f" "{connection_file}" ];
	language = "python";
      };
    };
  };
  
  services.openvpn.servers.myvpn = {
    config = ''
      config /etc/nixos/vpn/client.ovpn
      '';
    autoStart = false;
  };

  hardware.bluetooth = {
    enable = true;
    powerOnBoot = true;
    settings = {
      General = {
        Experimental = true;
	FastConnectable = true;
      };
      Policy = {
        AutoEnable = true;
      };
    };
  };
  services.blueman.enable = true;
  # Enable touchpad support (enabled default in most desktopManager).
  # services.xserver.libinput.enable = true;

  # Define a user account. Don't forget to set a password with ‘passwd’.
  users.users.bobi = {
    isNormalUser = true;
    description = "Bobi";
    extraGroups = [ "networkmanager" "wheel" ];
    packages = with pkgs; [
      kdePackages.kate
    #  thunderbird
    ];
  };

  # Install firefox.
  programs.firefox.enable = true;
  programs.nix-ld.enable = true;
  programs.nix-ld.libraries = with pkgs; [
    stdenv.cc.cc.lib
    zlib
    glib
    xorg.libX11
    libGL
    glib
    libxcb
  ];
  fonts.packages = with pkgs; [
    nerd-fonts.jetbrains-mono
    monocraft
  ];
  # Allow unfree packages
  nixpkgs.config.allowUnfree = true;
  nixpkgs.config.permittedInsecurePackages = [
    "broadcom-sta-6.30.223.271-59-6.12.93"
  ];
  boot.extraModulePackages = [ config.boot.kernelPackages.broadcom_sta ];
  boot.kernelModules = [ "wl" ];
  boot.blacklistedKernelModules = [ "b43" "bcma" "brcmsmac" ];
  hardware.enableRedistributableFirmware = true;
  # List packages installed in system profile. To search, run:
  # $ nix search wget
  environment.systemPackages = with pkgs; [
  #  vim # Do not forget to add an editor to edit configuration.nix! The Nano editor is also installed by default.
  #  wget
    nodejs
    neovim
    alacritty
    kitty
    git
    fastfetch
    eww
    grim
    slurp
    ollama
    hyprpaper
    rofi
    pamixer
    nerd-fonts.jetbrains-mono
    socat
    gcc
    gnumake
    jq
    pavucontrol
    keepassxc
    brightnessctl
    unzip
    emacs
    killall
    ghc
    cabal-install
    mu
    isync
    msmtp
    pass
    gnupg
    gh
    python3
    python3Packages.pip
    uv
    playerctl
    wget
    monocraft
    chromium
    pipes
    cava
  ];
  environment.etc = {
    "xdg/applications/youtube.desktop".text = ''
      [Desktop Entry]
      Type=Application
      Name=YouTube
      Comment=Youtube
      Exec=${pkgs.chromium}/bin/chromium --app=https://youtube.com
      Icon=chromium
      Terminal=false
      Categories=Network;
    '';
    "xdg/applications/discord.desktop".text = ''
      [Desktop Entry]
      Type=Application
      Name=Discord
      Comment=Discord
      Exec=${pkgs.chromium}/bin/chromium --app=https://discord.com/channels/@me
      Icon=chromium
      Terminal=false
      Categories=Network;
    '';
    "xdg/applications/claude.desktop".text = ''
      [Desktop Entry]
      Type=Application
      Name=Claude
      Comment=Claude
      Exec=${pkgs.chromium}/bin/chromium --app=https://claude.com
      Icon=chromium
      Terminal=false
      Categories=Network;
    '';
  };
  # Some programs need SUID wrappers, can be configured further or are
  # started in user sessions.
  # programs.mtr.enable = true;
  # programs.gnupg.agent = {
  #   enable = true;
  #   enableSSHSupport = true;
  # };

  # List services that you want to enable:

  # Enable the OpenSSH daemon.
  # services.openssh.enable = true;

  # Open ports in the firewall.
  # networking.firewall.allowedTCPPorts = [ ... ];
  # networking.firewall.allowedUDPPorts = [ ... ];
  # Or disable the firewall altogether.
  # networking.firewall.enable = false;

  # This value determines the NixOS release from which the default
  # settings for stateful data, like file locations and database versions
  # on your system were taken. It‘s perfectly fine and recommended to leave
  # this value at the release version of the first install of this system.
  # Before changing this value read the documentation for this option
  # (e.g. man configuration.nix or on https://nixos.org/nixos/options.html).
  system.stateVersion = "25.11"; # Did you read the comment?

}
