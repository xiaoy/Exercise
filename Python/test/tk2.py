from tkinter import *


def callback(event):
    print("clicked at:", event.x, event.y)


def key(event):
    print("key:", repr(event.char))

root = Tk()

frame = Frame(root, width=100, height=100)
frame.bind("<Button-1>", callback)
frame.bind("<Key>", key)
frame.pack()

root.mainloop()
