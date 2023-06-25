
findEvenIndex :: [Int] -> Int
findEvenIndex arr = loopInts arr 0

loopInts :: [Int] -> Int -> Int
loopInts arr ind    | length arr == ind = -1
                    | otherwise = if sum left == sum right then ind else loopInts arr (ind+1)
                                    where   left = take ind arr
                                            right = drop (ind+1) arr