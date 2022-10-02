import tkinter as tk
from tkinter.constants import *

white_path = 'io/time_white'
black_path = 'io/time_black'
switch_path = 'io/switch_value'

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

def getTime(in_file):
    """reads time (in seconds, float) from 'in_file' and returns time as string
    (HH:MM:SS.xxx)"""
    time_format = "{hours:02}:{minutes:02}:{seconds:06.3f}"
    with open(in_file) as f:
        t = float(f.readline())
        t_str = time_format.format(hours = int(t//3600),
                                   minutes = int((t%3600)//60),
                                   seconds = t%60)
    return t_str

def getSwitch(switch_file):
    """ reads first character from already open switch_file """
    switch_file.seek(0,0)
    return int(switch_file.read(1))

def clock():
    global switch_file
    switch_state = getSwitch(switch_file)
    if switch_state == 0:
        white_label.config(text=getTime(white_path))
        white_label.after(1, clock)
    elif switch_state == 1:
        black_label.config(text=getTime(black_path))
        black_label.after(1, clock)

switch_file = open(switch_path)


white_frame = tk.Frame(window, bg='#ffffff') #, height=frameheight, width=framewidth)
white_frame.pack(side=LEFT, expand=TRUE, fill=BOTH)
white_label = tk.Label(white_frame, text=getTime(white_path), font=(font,
                                                                     fontsize),
                       fg='black', bg='white')
white_label.pack(padx=padx, pady=pady)

black_frame = tk.Frame(window, bg='#000000', height=win_height,
                       width=win_width/2)
black_frame.pack(side=RIGHT, expand=TRUE, fill=BOTH)
black_label = tk.Label(black_frame, text=getTime(black_path), font=(font, fontsize),
                       fg='white', bg='#000000')
black_label.pack(padx=padx, pady=pady)


clock()


window.mainloop()

switch_file.close()

#frame = tk.Frame(window)   # create frame in window


