-- Return the greatest subarray sum within the array of integers passed in.
maxSequence :: [Int] -> Int
maxSequence [] = 0
maxSequence xs = maximum [sum x | x <- otherFunction xs 0]

-- Return all lists of consecutive numbers
otherFunction :: [Int] -> Int -> [[Int]]
otherFunction [] _ = []
otherFunction (x:xs) n  | n >= length xs = []
                        | otherwise = take n xs : otherFunction (x:xs) (n+1) ++ otherFunction xs 0  


