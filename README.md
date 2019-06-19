# C++ RLU Example Bot

Example c++ bot for the [RLBot framework](https://github.com/RLBot/RLBot) that uses [RLUtilities](https://github.com/samuelpmish/RLUtilities).

## How to use:
- Run `build.bat`. This will also clone the RLUtilities repo. 
- Copy the latest dll files from the RLBot pip package to the `release` folder.
  - the dll files are typically found at `\AppData\Local\Programs\Python\Python37-32\Lib\site-packages\rlbot\dll`
- Start a Rocket League match by running `release/run.bat`.

## Releasing a bot:
You can share your bot by zipping everything in the `release` folder.