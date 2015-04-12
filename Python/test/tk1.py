from tkinter import *


class App:
    def __init__(self, master):
        frame = Frame()
        frame.pack()

        self.button = Button(frame, text='Quit', fg='red', command=frame.quit)
        self.button.pack(side=LEFT)

        self.say_hi_buttion = Button(frame, text='say, hi',
                                     command=self.say_hi)

        self.say_hi_buttion.pack(side=LEFT)

    def say_hi(self):
        print("hi, everyone")

root = Tk()

app = App(root)

root.mainloop()
root.destroy()
