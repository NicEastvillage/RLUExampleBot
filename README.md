# RLU Example Bot

Example c++ bot for the [RLBot framework](https://github.com/RLBot/RLBot) that uses [RLUtilities](https://github.com/samuelpmish/RLUtilities).

## How to start
- Run `build.bat`. This will also clone the RLUtilities repo. 
- Copy the latest dll files from the RLBot pip package to the `release` folder.
  - the dll files are typically found at `\AppData\Local\Programs\Python\Python37-32\Lib\site-packages\rlbot\dll`
- Start a Rocket League match by running `release\run.bat`.

TIP: During development, if you comment out `path = CppExampleBot.exe` in `CppPythonAgent.cfg` the bot must be manually started for matches, which means you don't have to restart the match to see your changes. Just recompile and rerun `CppExampleBot.exe`.

## Releasing a bot
You can share your bot by zipping everything in the `release` folder. Remember to make sure your bot auto-starts and all the info in the config files are correct.