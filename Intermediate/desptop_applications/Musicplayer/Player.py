# Kay_JEY / 25-3-21 /
from tkinter import *  
from tkinter import messagebox
from tkinter import filedialog
from PIL import Image 
import os 
import pygame

#colors
base_color = '#0079bf'
primary_color = '#123456'
secondary_color='#e4f0f6'

w=50
h=50
playlist=[]

root = Tk()

pausepointer =0
iconimage = 'images/yellowhead.ico'
bgimage='images/bg4.png'
pauseimage='images/buttons/pause.png'
playimage='images/buttons/play.png'
skipimage='images/buttons/estop.png'


# bg=PhotoImage(file=bgimage)
pauseimageh=PhotoImage(pauseimage)
pauseimageh=pauseimageh.zoom(50,50)
playimageh=PhotoImage(playimage)
skipimageh=skipimage

def browsefiles():
    global filename_path
    filename_path = filedialog.askopenfilename()
    add_songs(filename_path)

def add_songs(filename):
    filename=os.path.basename(filename)
    index=0
    playlistbox.insert(index,filename)
    playlist.insert(index, filename_path)
    index=index+1

def pausebutton():
    try:
        global pausepointer
        if pausepointer ==0:
            pygame.mixer.music.unpause()
            pausepointer =1
        elif pausepointer ==1:
            pygame.mixer.music.pause()
            pausepointer =0
    except:
        messagebox.showerror('file not found','PLAY A SONG TO PAUSE IT')
        print("PAUSE ERROR")

def skipbutton():
    try:
        global pasusepointer
        selectedsongindex =+1
        playthis= playlist[selectedsongindex]
        pygame.mixer.init(44100, -16,2,2048)
        pygame.mixer.music.load(playthis)
        pygame.mixer.music.play(-1)
        pausepointer = 1
    except:
        messagebox.showerror('song not slected','PLEASE Select a song first')
        print("PLAY ERROR")


def lyricsbutton():
    try:
        artist = inputartist.get(1.0 , "end-1c")
        song_title= inputsong.get(1.0,"end-1c")
        url= 'https://api.lyrics.ovh/v1/' + artist + '/' + song_title

        response = requests.get(url)
        json_data = json.loads(response.content)
        lyrics = json_data["lyrics"]

        lyricsarea.insert(END,lyrics)

    except:
        messagebox.showerror('LYRICS NOT FOUND','PLEASE ENTER SONG NAME AND ARTIST')
        print("PLAY ERROR")


def playbutton(): # function to play a song
    try:
        global pausepointer
        global selectedsongindex
        selectedsong= playlistbox.curselection()
        selectedsongindex=int(selectedsong[0])
        playthis= playlist[selectedsongindex]
        pygame.mixer.init(44100, -16,2,2048)
        pygame.mixer.music.load(playthis)
        pygame.mixer.music.play(-1)
        pausepointer = 1
    except:
        messagebox.showerror('file not found','Akatsuki cant find the files')
        print("PLAY ERROR")


root.title('AKATSUI PLAYER')
root.geometry('700x700')
root.config(bg= primary_color)
root.iconbitmap(iconimage)


#creating frames
leftframe = Frame(root, background = primary_color)
leftframe.pack(side=LEFT)

rightframe = Frame(root, background=primary_color, borderwidth= 1)
rightframe.pack(side= RIGHT)


brFrame = Frame(rightframe, background=primary_color,  borderwidth= 1)
brFrame.pack(side=BOTTOM)

blFrame = Frame(leftframe, background=primary_color, borderwidth= 1)
blFrame.pack(side=BOTTOM)

trFrame = Frame(rightframe, background=primary_color,  borderwidth= 1)
trFrame.pack(side=TOP)

tlFrame = Frame(leftframe, background=primary_color, borderwidth= 1)
tlFrame.pack(side=TOP)

'''mycanvas = Canvas(root, width = 10, height =10)
mycanvas.pack(fill='both', expand=True)
mycanvas.create_image(0,0 ,image=bg)'''

#Cretaing menubar
menubar = Menu(root)
root.config(menu=menubar)

#creating submenu called FILE
subMenu = Menu(menubar, tearoff =0)
menubar.add_cascade(label = "FILE", menu = subMenu)
subMenu.add_command(label = "OPEN", command = browsefiles)
subMenu.add_command(label = "EXIT",command = root.destroy)
#creating submenu called HELP
subMenu = Menu(menubar, tearoff =0)
menubar.add_cascade(label = "HELP", menu = subMenu)
subMenu.add_command(label = "About Us")
subMenu.add_command(label = "Reach Us")


l1 = Label(tlFrame, text= "PLAY LIST", bg = primary_color,fg = "white" )
l1.pack(pady=10)
l2 = Label(root, text = "AKATSUKI PLAYER", bg = primary_color,fg = "white" )
l2.pack()
b1 = Button(brFrame,text = "PAUSE",command = pausebutton ,activeforeground = "purple",activebackground = "black",height=3, width=5)
b1.pack(side = LEFT, padx=10)
b2 = Button(brFrame, text = "PLAY",command = playbutton , activeforeground = "purple",activebackground = "black",height=3, width=5)
b2.pack(side=LEFT,padx=10)
b3 = Button(brFrame , text = "SKIP",command=skipbutton ,activeforeground = "purple",activebackground = "black" ,height=3, width=5)
b3.pack(side=LEFT,padx=10)
b4 = Button(brFrame, text = "LYRICS",activeforeground = "purple",activebackground = "black",height=3, width=5)
b4.pack(side=LEFT,padx=10)

b5 = Button(blFrame, text="+SONGS", command = browsefiles)
b5.pack(side=LEFT, padx=10,pady=30)
b6 = Button(blFrame, text="-SONGS")
b6.pack(side=LEFT,padx=10,pady=30)

lyricsarea = Text(trFrame,width=100,height=30)
lyricsarea.insert(INSERT,"HERE LYRICS OF SONG")
lyricsarea.insert(END," WILL BE DISPLAYED")
lyricsarea.pack(padx = 30, pady = 30)

playlistbox = Listbox(tlFrame,)
playlistbox.pack()



root.mainloop()
