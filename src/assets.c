#include <stdio.h>
#include <stdlib.h>

#include "../include/assets.h"
#include "../include/utils.h"

void displayLogo(void) {
    printf("                                  ,'\n");
    printf("    _.----.        ____         ,'  _\\   ___    ___     ____\n"); 
    printf("_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"); 
    printf("\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"); 
    printf(" \\.    \\ \\   |  __  |  |/    ,' ,'_  `.  |          | __  |    \\|  |\n"); 
    printf("   \\    \\/   / ,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"); 
    printf("    \\     ,-'/  /   \\    ,'   | \\/ / ,' .|         /  /   \\  |     |\n"); 
    printf("     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"); 
    printf("      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"); 
    printf("       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"); 
    printf("        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"); 
    printf("                                `'                            '-._|\n");
}


void displayStartCombat() {
    clear();
    printf("\nUm treinador selvagem apareceu!\n");
}

void printCharacterArt(const char* characterName) {
    if (strcmp(characterName, "Charmander") == 0) {
        printf("              _.--\"\"`-..\n");
        printf("            ,'          `.\n");
        printf("          ,'          __  `.\n");
        printf("         /|          \" __   \\\n");
        printf("        , |           / |.   .\n");
        printf("        |,'          !_.'|   |\n");
        printf("      ,'             '   |   |\n");
        printf("     /              |`--'|   |\n");
        printf("    |                `---'   |\n");
        printf("     .   ,                   |                       ,\".\n");
        printf("      ._     '           _'  |                    , ' \\ `\n");
        printf("  `.. `.`-...___,...---\"\"    |       __,.        ,`\"   L,|\n");
        printf("  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\\n");
        printf("-:..     `. `-..--_.,.<       `\"      / `.        `-/ |   .\n");
        printf("  `,         \"\"\"\"'     `.              ,'         |   |  ',,\n");
        printf("    `.      '            '            /          '    |'. |/\n");
        printf("      `.   |              \\       _,-'           |       ''\n");
        printf("        `._'               \\   '\"\\                .      |\n");
        printf("           |                '     \\                `._  ,'\n");
        printf("           |                 '     \\                 .'|\n");
        printf("           |                 .      \\                | |\n");
        printf("           |                 |       L              ,' |\n");
        printf("           `                 |       |             /   '\n");
        printf("            \\                |       |           ,'   /\n");
        printf("          ,' \\               |  _.._ ,-..___,..-'    ,'\n");
        printf("         /     .             .      `!             ,j'\n");
        printf("        /       `.          /        .           .'/\n");
        printf("       .          `.       /         |        _.'.'\n");
        printf("        `.          7`'---'          |------\"'_.'\n");
        printf("       _,.`,_     _'                ,''-----\"'\n");
        printf("   _,-_    '       `.     .'      ,\\\n");
        printf("   -\" /`.         _,'     | _  _  _.|\n");
        printf("    \"\"--'---\"\"\"\"\"'        `' '! |! /\n");
        printf("                            `\" \" -'\n");
        printf("\n");
        printf("\n");
    } else if (strcmp(characterName, "Squirtle") == 0) {
        printf("               _,........__\n");
        printf("            ,-'            \"`-.\n");
        printf("          ,'                   `-.\n");
        printf("        ,'                        \\\n");
        printf("      ,'                           .\n");
        printf("      .'\\               ,\"\".       `\n");
        printf("     ._.'|             / |  `       \\\n");
        printf("     |   |            `-.'  ||       `.\n");
        printf("     |   |            '-._,'||       | \\\n");
        printf("     .`.,'             `..,'.'       , |`-.\n");
        printf("     l                       .'`.  _/  |   `.\n");
        printf("     `-.._'-   ,          _ _'   -\" \\  .     `\n");
        printf("`.\"\"\"\"\"'-.`-...,---------','         `. `....__.\n");
        printf(".'        `\"-..___      __,'\\          \\  \\     \\\n");
        printf("\\_ .          |   `\"\"\"\"'    `.           . \\     \\\n");
        printf("  `.          |              `.          |  .     L\n");
        printf("    `.        |`--...________.'.        j   |     |\n");
        printf("      `._    .'      |          `.     .|   ,     |\n");
        printf("         `--,\\       .            `7\"\"' |  ,      |\n");
        printf("            ` `      `            /     |  |      |    _,-'\"\"\"`-.\n");
        printf("             \\ `.     .          /      |  '      |  ,'          `.\n");
        printf("              \\  v.__  .        '       .   \\    /| /              \\\n");
        printf("               \\/    `\"\"\\\"\"\"\"\"\"\"`.       \\   \\  /.''                |\n");
        printf("                `        .        `._ ___,j.  `/ .-       ,---.     |\n");
        printf("                ,`-.      \\         .\"     `.  |/        j     `    |\n");
        printf("               /    `.     \\       /         \\ /         |     /    j\n");
        printf("              |       `-.   7-.._ .          |\"          '         /\n");
        printf("              |          `./_    `|          |            .     _,'\n");
        printf("              `.           / `----|          |-............`---'\n");
        printf("                \\          \\      |          |\n");
        printf("               ,'           )     `.         |\n");
        printf("                7____,,..--'      /          |\n");
        printf("                                  `---.__,--.'\n");
    } else if (strcmp(characterName, "Bulbasaur") == 0) {
         printf("                                           /\n");
        printf("                        _,.------....___,.' ',.-.\n");
        printf("                     ,-'          _,.--\"        |\n");
        printf("                   ,'         _.-'              .\n");
        printf("                  /   ,     ,'                   `\n");
        printf("                 .   /     /                     ``.\n");
        printf("                 |  |     .                       \\.\\\n");
        printf("       ____      |___._.  |       __               \\ `.\n");
        printf("     .'    `---\"\"       ``\"-.--\"'`  \\               .  \\\n");
        printf("    .  ,            __               `              |   .\n");
        printf("    `,'         ,-\"'  .               \\             |    L\n");
        printf("   ,'          '    _.'                -._          /    |\n");
        printf("  ,`-.    ,\".   `--'                      >.      ,'     |\n");
        printf(" . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'\n");
        printf(" ||:, .           ,'  ;  /  / \\ `        `.    .      .'/\n");
        printf(" j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /\n");
        printf("/ L:_  |                 .  \"' :_;                `.'.'\n");
        printf(".    \"\"'                  \"\"\"\"\"'                    V\n");
        printf(" `.                                 .    `.   _,..  `\n");
        printf("   `,_   .    .                _,-'/    .. `,'   __  `\n");
        printf("    ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  .\n");
        printf("   /   `. \"`-.--\"'         _,' ,'     `---' |    `./  |\n");
        printf("  .   _  `\"\"'--.._____..--\"   ,             '         |\n");
        printf("  | .\" `. `-.                /-.           /          ,\n");
        printf("  | `._.'    `,_            ;  /         ,'          .\n");
        printf(" .'          /| `-.        . ,'         ,           ,\n");
        printf(" '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'\n");
        printf(" `\"^--'..'   '-`-^-'\"--    `-^-'`.''\"\"\"\"\"`.,^.`.--'\n");
        printf("\n");
        printf("\n");


    } else if (strcmp(characterName, "Pikachu") == 0) {
         printf("                                             ,-.\n");
        printf("                                          _.|  '\n");
        printf("                                        .'  | /\n");
        printf("                                      ,'    |'\n");
        printf("                                     /      /\n");
        printf("                       _..----\"\"---.'      /\n");
        printf(" _.....---------...,-\"\"                  ,'\n");
        printf(" `-._  \\                                /\n");
        printf("     `-.+_            __           ,--. .\n");
        printf("          `-.._     .:  ).        (`--\"| \\\n");
        printf("               7    | `\" |         `...'  \\\n");
        printf("               |     `--'     '+\"        ,\". ,\"\"-\n");
        printf("               |   _...        .____     | |/    '\n");
        printf("          _.   |  .    `.  '--\"   /      `./     j\n");
        printf("         \\' `-.|  '     |   `.   /        /     /\n");
        printf("         '     `-. `---\"      `-\"        /     /\n");
        printf("          \\       `.                  _,'     /\n");
        printf("           \\        `                        .\n");
        printf("            \\                                j\n");
        printf("             \\                              /\n");
        printf("              `.                           .\n");
        printf("                +                          \\\n");
        printf("                |                           L\n");
        printf("                |                           |\n");
        printf("                |  _ /,                     |\n");
        printf("                | | L)'..                   |\n");
        printf("                | .    | `                  |\n");
        printf("                '  \\'   L                   '\n");
        printf("                 \\  \\   |                  j\n");
        printf("                  `. `__'                 /\n");
        printf("                _,.--.---........__      /\n");
        printf("               ---.,'---`         |   -j\"\n");
        printf("                .-'  '....__      L    |\n");
        printf("              \"\"--..    _,-'       \\ l||\n");
        printf("                  ,-'  .....------. `||'\n");
        printf("               _,'                /\n");
        printf("             ,'                  /\n");
        printf("            '---------+-        /\n");
        printf("                     /         /\n");
        printf("                   .'         /\n");
        printf("                 .'          /\n");
        printf("               ,'           /\n");
        printf("             _'....----\"\"\"\"\"\n");
    } else if (strcmp(characterName, "Jigglypuff") == 0) {
        printf("   ,..__\n");
        printf("  |  _  `--._                                  _.--\"\"\"`.\n");
        printf("  |   |._    `-.        __________         _.-'    ,|' |\n");
        printf("  |   |  `.     `-..--\"\"_.        `\"\"-..,-'      ,' |  |\n");
        printf("  L   |    `.        ,-'                      _,'   |  |\n");
        printf("   .  |     ,'     ,'            .           '.     |  |\n");
        printf("   |  |   ,'      /               \\            `.   |  |\n");
        printf("   |  . ,'      ,'                |              \\ /  j\n");
        printf("   `   \"       ,                  '               `   /\n");
        printf("    `,         |                ,'                  '+\n");
        printf("    /          |             _,'                     `\n");
        printf("   /     .-\"\"\"'L          ,-' \\  ,-'\"\"\"\"`-.           `\n");
        printf("  j    ,' ,.+--.\\        '    ',' ,.,-\"--._`.          \\\n");
        printf("  |   / .'  L    `.        _.'/ .'  |      \\ \\          .\n");
        printf(" j   | | `--'     |`+-----'  . j`._,'       L |         |\n");
        printf(" |   L .          | |        | |            | |         |\n");
        printf(" |   `\\ \\        / j         | |            | |         |\n");
        printf(" |     \\ `-.._,.- /           . `         .'  '         |\n");
        printf(" l      `-..__,.-'             `.`-.....-' _.'          '\n");
        printf(" '                               `-.....--'            j\n");
        printf("  .                  -.....                            |\n");
        printf("   L                  `---'                            '\n");
        printf("    \\                                                 /\n");
        printf("     ` \\                                        ,   ,'\n");
        printf("      `.`.    |                        /      ,'   .\n");
        printf("        . `._,                        |     ,'   .'\n");
        printf("         `.                           `._.-'  ,-'\n");
        printf("    _,-\"\"\"\"`-,                             _,'\"-.._\n");
        printf("  ,'          `-.._                     ,-'        `.\n");
        printf(" /             _,' `\"-..___     _,..--\"`.            `.\n");
        printf("|         _,.-'            `\"\"\"'         `-._          \\\n");
        printf("`-....---'                                   `-.._      |\n");
        printf("                                                  `--...'\n");
    } else if (strcmp(characterName, "Rattata") == 0) {
        printf("                                      ,'\"\"`--.\n");
        printf("                                     |     __ `-.\n");
        printf("                                     |    /  `.  `.\n");
        printf("                                      \\        ,   `.\n");
        printf("                                       `.      \\_    `.\n");
        printf("                                         `.    | `.    \\\n");
        printf("                                           `--\"    `.   `\n");
        printf("                                                     `.  `\n");
        printf("                 ,.._                                  \\  `\n");
        printf("               /_,.  `.                                 \\  `\n");
        printf("              j/   .   \\                  ___            \\  \\\n");
        printf("              |    |   `____         _,--'   `.           .  L\n");
        printf("               L  /`--\"'    `'--._ ,'   ,-`'\\ |            . |\n");
        printf("                |-                /  ,''     ||            | |\n");
        printf("     -v._      /                   ,'        ||            | |\n");
        printf("       `.`-._,'               _     \\        |j    _,...   | |\n");
        printf("         `,.'             _,-. \\     |      /,---\"\"     `- | |\n");
        printf("        .'              ,\".   ||     `..___/,'            `' |\n");
        printf("        |   ,         _/`-'  /,'                            `|\n");
        printf("        |-.__.-'\"''\"\"' \"\"\"\"\"\"\"\"--`_,...-----''''--...--      `.\n");
        printf("         `.____,..              \"\"   __,..---\"\"\"              |\n");
        printf("          |       `              --\"'.                        `\n");
        printf("          |     ,' `._                \\'                       `\n");
        printf("          | |  .^.    `.             /                          `.\n");
        printf("         ,'_]__|  \\   / `.          /          /____._            `._\n");
        printf("       ,'          \\ j    '        /          /       `.             `.\n");
        printf(" ___,.' `._       __L/    |     __'          /     _, / \\             |\n");
        printf("`-._       L,.-\"\"\"  .    ,' _.-','          /-----'-./   `--.         |\n");
        printf("   '   / ,'         '..'\"_,'    /         F /  .\"'_,'        |.__     '\n");
        printf("  / ,.\\,'              \"\"      /         / (,'\\ .'        ,.-\"'  `.  j\n");
        printf("  -'   '                      /        ,'     `\"         / __/' .- ,'\n");
        printf("                           __.'\"`.    /                 `-' | _,L,'\n");
        printf("                         .',      `\"\"'                      '/,--\n");
        printf("                          / _..' _,,'\n");
        printf("                          ,' `-\"'\n");
        }

}