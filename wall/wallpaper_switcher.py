#!/usr/bin/env python3
import os
import subprocess
import tkinter as tk
from tkinter import messagebox
from PIL import Image, ImageTk

WALLPAPER_DIR = os.path.expanduser("~/wall")
WALLPAPERS = ["wall1.jpg", "wall2.jpeg", "wall3.png", "wall4.jpg", "wall5.jpg"]
THUMB_W, THUMB_H = 320, 180
BG       = "#0d0f14"
PANEL    = "#13161e"
ACCENT   = "#7aa2f7"
TEXT     = "#c0caf5"
SUBTEXT  = "#565f89"
BORDER   = "#1a1b26"
HOVER    = "#1e2030"
ACTIVE   = "#24283b"
FONT_H   = ("Inter", 13, "bold")
FONT_B   = ("Inter", 11)
FONT_S   = ("Inter", 9)


def apply_wallpaper(path: str) -> None:
    abs_path = os.path.abspath(path)

    try:
        subprocess.run(
            ["hyprctl", "hyprpaper", "preload", abs_path],
            check=True, capture_output=True
        )
        subprocess.run(
            ["hyprctl", "hyprpaper", "wallpaper", f",{abs_path}"],
            check=True, capture_output=True
        )
        subprocess.run(
            ["eww", "reload"],
            capture_output=True 
        )
        return
    except (subprocess.CalledProcessError, FileNotFoundError):
        pass

    try:
        subprocess.run(["swww", "img", abs_path], check=True, capture_output=True)
        return
    except (subprocess.CalledProcessError, FileNotFoundError):
        pass

    messagebox.showerror(
        "Nemas hyprland be",
    )


class WallCard(tk.Frame):
    def __init__(self, parent, index: int, filename: str, on_apply, **kw):
        super().__init__(parent, bg=PANEL, bd=0, highlightthickness=1,
                         highlightbackground=BORDER, **kw)
        self.index    = index
        self.filename = filename
        self.on_apply = on_apply
        self.path     = os.path.join(WALLPAPER_DIR, filename)
        self._active  = False
        self._img_ref = None

        self._build()
        self.bind("<Enter>", self._on_enter)
        self.bind("<Leave>", self._on_leave)

    def _build(self):
        thumb_frame = tk.Frame(self, bg=BORDER, width=THUMB_W, height=THUMB_H)
        thumb_frame.pack_propagate(False)
        thumb_frame.pack(padx=12, pady=(12, 6))

        self.thumb_label = tk.Label(thumb_frame, bg=BORDER, cursor="hand2")
        self.thumb_label.pack(fill="both", expand=True)
        self.thumb_label.bind("<Button-1>", lambda _: self._apply())
        self._load_thumbnail()

        name_row = tk.Frame(self, bg=PANEL)
        name_row.pack(fill="x", padx=12)

        idx_lbl = tk.Label(name_row, text=f"{self.index + 1:02d}",
                           font=FONT_S, bg=PANEL, fg=SUBTEXT)
        idx_lbl.pack(side="left")

        tk.Label(name_row, text=self.filename,
                 font=FONT_B, bg=PANEL, fg=TEXT,
                 anchor="w").pack(side="left", padx=(6, 0))

        self.btn = tk.Button(
            self, text="Apply",
            font=FONT_B, bg=ACTIVE, fg=TEXT,
            activebackground=ACCENT, activeforeground=BG,
            relief="flat", bd=0, cursor="hand2",
            padx=0, pady=6,
            command=self._apply
        )
        self.btn.pack(fill="x", padx=12, pady=(6, 12))

    def _load_thumbnail(self):
        if not os.path.isfile(self.path):
            self.thumb_label.config(text="[not found]", fg=SUBTEXT)
            return
        try:
            img = Image.open(self.path)
            img.thumbnail((THUMB_W, THUMB_H), Image.LANCZOS)
            photo = ImageTk.PhotoImage(img)
            self.thumb_label.config(image=photo, text="")
            self._img_ref = photo 
        except Exception as exc:
            self.thumb_label.config(text=f"[error: {exc}]", fg=SUBTEXT)

    def _apply(self):
        self.on_apply(self)

    def _on_enter(self, _=None):
        if not self._active:
            self.config(highlightbackground=SUBTEXT)

    def _on_leave(self, _=None):
        if not self._active:
            self.config(highlightbackground=BORDER)

    def set_active(self, active: bool):
        self._active = active
        if active:
            self.config(highlightbackground=ACCENT, highlightthickness=2)
            self.btn.config(text="✓ Active", bg=ACCENT, fg=BG,
                            activebackground=ACCENT, activeforeground=BG)
        else:
            self.config(highlightbackground=BORDER, highlightthickness=1)
            self.btn.config(text="Apply", bg=ACTIVE, fg=TEXT,
                            activebackground=ACCENT, activeforeground=BG)


class App(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Wallpaper Switcher")
        self.configure(bg=BG)
        self.resizable(False, False)
        self.bind("<Escape>", lambda _: self.destroy())
        self._cards: list[WallCard] = []
        self._active_card: WallCard | None = None
        self._build()

    def _build(self):
        hdr = tk.Frame(self, bg=BG)
        hdr.pack(fill="x", padx=24, pady=(20, 4))

        tk.Label(hdr, text="Wallpapers", font=("Inter", 18, "bold"),
                 bg=BG, fg=TEXT).pack(side="left")
        tk.Label(hdr, text="Hyprland", font=FONT_S,
                 bg=BG, fg=ACCENT).pack(side="right", pady=(4, 0))

        tk.Frame(self, bg=BORDER, height=1).pack(fill="x", padx=24, pady=(4, 16))

        grid = tk.Frame(self, bg=BG)
        grid.pack(padx=20, pady=(0, 20))

        cols = 3
        for i, name in enumerate(WALLPAPERS):
            row, col = divmod(i, cols)
            card = WallCard(grid, i, name, self._on_apply)
            card.grid(row=row, column=col, padx=8, pady=8, sticky="nsew")
            self._cards.append(card)

        status_bar = tk.Frame(self, bg=PANEL, height=32)
        status_bar.pack(fill="x", side="bottom")
        status_bar.pack_propagate(False)

        self.status_var = tk.StringVar(value="Select a wallpaper to apply it.")
        tk.Label(status_bar, textvariable=self.status_var,
                 font=FONT_S, bg=PANEL, fg=SUBTEXT,
                 anchor="w").pack(side="left", padx=14, pady=4)

        tk.Label(status_bar, text=WALLPAPER_DIR,
                 font=FONT_S, bg=PANEL, fg=BORDER,
                 anchor="e").pack(side="right", padx=14)

    def _on_apply(self, card: WallCard):
        if self._active_card:
            self._active_card.set_active(False)

        apply_wallpaper(card.path)
        card.set_active(True)
        self._active_card = card
        self.status_var.set(f"Applied: {card.filename}")


if __name__ == "__main__":
    app = App()
    app.mainloop()
