data Direction = North | East | West | South deriving (Eq)

dirReduce :: [Direction] -> [Direction]
dirReduce (x:y:xs)  | x == North && y == South = dirReduce xs
                    | x == South && y == North = dirReduce xs
                    | x == West && y == East = dirReduce xs
                    | x == East && y == West = dirReduce xs
                    | otherwise = x : dirReduce(y:xs)