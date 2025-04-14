
#* Audio Speakers via bluetooth

from pygame import mixer

mixer.init()
mixer.music.load("myFile.wav")
mixer.music.play()
while mixer.music.get_busy() == True:
    continue
