#!/usr/bin/env bash

export PATH="/run/current-system/sw/bin:$HOME/.nix-profile/bin:$PATH"

eww update keyhov=true
(sleep 0.45 && eww update keyrev="$(eww get keyhov)") &
