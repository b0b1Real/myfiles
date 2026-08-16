#!/usr/bin/env bash

export PATH="/run/current-system/sw/bin:$HOME/.nix-profile/bin:$PATH"

if [[ -z $(eww active-windows | grep 'usrctl') ]]; then
    eww open usrctl && eww update ctlrev=true
else
    eww update ctlrev=false
    (sleep 0.2 && eww close usrctl) &
fi
