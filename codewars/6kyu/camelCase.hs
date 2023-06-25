
import Data.Char

toCamelCase :: String -> String
toCamelCase [] = []
toCamelCase [x] | x == '-' || x == '_' = []
                | otherwise = [x]
toCamelCase [x,y] | x == '-' || x == '_' = [toUpper y]
                  | otherwise = [x, y]
toCamelCase (x:y:str)   | x == '-' || x == '_' = toUpper y : toCamelCase str
                        | otherwise = x : toCamelCase(y:str)

