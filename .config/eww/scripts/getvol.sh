#!/usr/bin/env bash

export PATH="/run/current-system/sw/bin:$HOME/.nix-profile/bin:$PATH"

while true; do
    mute=$(pamixer --get-mute)
    if [ "$mute" = true ]; then
        eww update volico="󰖁"
        echo "0"
    else
        eww update volico="󰕾"
        pamixer --get-volume
    fi
    sleep 0.5
done
