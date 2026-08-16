#!/usr/bin/env bash

export PATH="/run/current-system/sw/bin:$HOME/.nix-profile/bin:$PATH"

if [[ -z $(eww active-windows | grep 'calendar') ]]; then
    eww open calendar && eww update calrev=true
else
    eww update calrev=false
    (sleep 0.2 && eww close calendar) &
fi
