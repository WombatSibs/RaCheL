import tkinter as tk
from tkinter.constants import *

win_width = 1500
win_height = 400
win_geom = '{}x{}'.format(win_width, win_height)

window = tk.Tk()   # initialize new window
window.title('RaCheL')
window.geometry(win_geom)

# labels displaying the time for black and white
#frameheight = 200
#framewidth = 400
font = 'Arial'
fontsize = 70
padx = 0
pady = win_height/2 - fontsize
time_format = "{hours:02}:{minutes:02}:{seconds:06.3f}"

with open('io/time_white') as w_file:
    w_time = float(w_file.readline())
    w_str = time_format.format(hours = int(w_time//3600),
                                             minutes = int((w_time%3600)//60),
                                             seconds = w_time%60)
white_frame = tk.Frame(window) #, height=frameheight, width=framewidth)
white_frame.pack(side=LEFT, expand=TRUE, fill=BOTH)
white_label = tk.Label(white_frame, text= w_str, font=(font, fontsize))
white_label.pack(padx=padx, pady=pady)

with open('io/time_black') as b_file:
    b_time = float(b_file.readline())
    b_str = time_format.format(hours = int(b_time//3600),
                                             minutes = int((b_time%3600)//60),
                                             seconds = b_time%60)
black_frame = tk.Frame(window, bg='#000000', height=win_height,
                       width=win_width/2)
black_frame.pack(side=RIGHT, expand=TRUE, fill=BOTH)
black_label = tk.Label(black_frame, text= b_str, font=(font, fontsize),
                       fg='white', bg='#000000')
black_label.pack(padx=padx, pady=pady)

tk.mainloop()

#frame = tk.Frame(window)   # create frame in window


