**Turn-Based Battle Game**

This game, inspired by classic electronic RPGs like Pokémon and Chrono Trigger, is an exercise for the Algorithm and Data Structures course in the Computer Science program at [cesar.school](https://cesar.school).   <br> 

Designed for two players, it offers a tactic turn-based battle experience where each participant selects three unique characters.  <br>

Each character is distinct, possessing individual Health Points, Resistances, Immunity, Vulnerability, Weakness and a set of three attacks. This varied design enhances the strategic depth of the game.  <br>

The game initially features six Types: Physical, Magical, Fire, Water, Poison, and Electric. To illustrate them, we have chosen a representative Pokémon for each type.  <br>

Due to its modularity, it´s easy to customize or create their characters and graphics through the manipulation of character.c, character.h, and assets.c files.  <br>


The game was developed in C (only with standard libraries), on WSL Ubuntu and MacOS enviroments with gcc compiler.<br>


To run it, a Makefile with commands is provided:
```
make run
```
Check to create folder and file for the ranking and the build in the root:

```
/build
/data/ranking.dat
```
<br>
The game is structured around three main cores:  <br>
<br>

**Characters: The heart of the game, where each character's design plays a role.**<br>


<img width="437" alt="character_rattata" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/5f8b5371-956d-4f71-bdb4-d0f92869b73a">  <br>
<img width="433" alt="character_rattata_art" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/a409cdd4-e6ef-4e82-8834-f4753e89fcdc">  <br>
<img width="215" alt="character_struct" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/8d33f00c-c50b-4e08-b0a4-c39505f77086">  <br>

**Combat: The battleground where strategies are tested and skills are showcased.**  


<img width="336" alt="main_combat" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/bad9f144-5704-4a8f-b9d1-312265320e70">  <br>
<img width="388" alt="combat_loop" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/f85e8cca-99e2-4960-a27b-1a868bb414e6">  <br>
<img width="743" alt="attack" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/4ce9de96-96d9-4886-aacf-0a63908abf2c">  <br>

**User Interface and Ranking: A simple interface and a competitive ranking system, adds to the overall experience.**  <br>


<img width="317" alt="main_init" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/e6dbb4f6-4cb5-45ed-bb0e-ad9ad1ee3512">  <br>
<img width="382" alt="update_ranking" src="https://github.com/pedro-coelho-dr/turnbasedgame/assets/111138996/d269d94c-7afe-49fe-a933-f77d405861dc">  <br>

[Presentation slides](https://www.canva.com/design/DAF0t4UKpcE/PBD7UuKRhi874yX0-XWVMw/edit?utm_content=DAF0t4UKpcE&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton) <br>

[Youtube](https://youtu.be/8PHuiFM10-w)

[![https://youtu.be/oxeSl30gNEc](https://img.youtube.com/vi/8PHuiFM10-w/0.jpg)](https://youtu.be/8PHuiFM10-w)

Developed by:<br>
[Pedro Coelho](https://github.com/pedro-coelho-dr) and [Camila Cirne](https://github.com/camilacirne)
<br>
Special thanks to the artists at ([asciiart.eu](https://www.asciiart.eu/video-games/pokemon)) and ([Matheus Faria](https://gist.github.com/MatheusFaria/4cbb8b6dbe33fd5605cf8b8f7130ba6d)) for their ASCII art contributions, which bring charm and nostalgia to our game.
