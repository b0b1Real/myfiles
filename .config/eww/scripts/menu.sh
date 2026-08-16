#!/usr/bin/env bash

export PATH="/run/current-system/sw/bin:$HOME/.nix-profile/bin:$PATH"

names=(
  "Firefox"
  "Emacs"
  "Alacritty"
)

execs=(
  "firefox"
  "emacs"
  "alacritty"
)

icons=(
  "/run/current-system/sw/share/icons/hicolor/128x128/apps/firefox.png"
  "/run/current-system/sw/share/icons/hicolor/scalable/apps/emacs.svg"
  "/run/current-system/sw/share/icons/hicolor/scalable/apps/Alacritty.svg"
)

terminal=(
  false
  false
  false
)

json="["
for i in "${!names[@]}"; do
  [[ $i -ne 0 ]] && json+=","
  json+="{\"name\":\"${names[$i]}\",\"exec\":\"${execs[$i]}\",\"icon\":\"${icons[$i]}\",\"terminal\":\"${terminal[$i]}\"}"
done
json+="]"
echo "$json"
