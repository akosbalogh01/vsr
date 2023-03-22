# VSR
Domain specific RGB-LED music visualiser system

### Usage
vsr.exe settings.ini xml/Playlist.xml

### CPP
VSR uses a C++ desktop host to control the embedded system and the music playlist. Host application was compiled using Code::Blocks, GCC10.  
Required libraries: SFML, TagLib.  
Controls:  
modifier key: left shift  

escape: exit application  
mousewheel: set maximum volume  
mod + mousewheel: set maximum brightness  
V: toggle FFT visualisation  
mod + V: toggle FFT transmission  
right cursor: start next song in playlist  
left cursor: start previous song in playlist  
mod + right cursor: jump forward 10 seconds in playback  
mod + left cursor: jump backward 10 seconds in playback  
space: pause/resume playback  
mod + space: toggle automatic start of next song  
D: toggle debug overlay  
mod + D: toggle debug overlay  

### MCU
VSR uses STM32 F446RE Nucleo board. MCU project was compiled using System Workbench for STM32.

### MPS
VSR uses JetBrains MetaProgramming System as the Domain Specific Development Environment. VSR language was build with MPS 2022.2.

### Demo
https://www.youtube.com/watch?v=KRuO5h96djY

#### Further reading
TDK.pdf contains the full project documentation in Hungarian.
