import Data.Char

disemvowel :: String -> String
disemvowel str = [x | x <- str, not (elem (toLower x) vowels)]
                where vowels = "aeiou"