digpow :: Integer -> Integer -> Integer
digpow n p = if out == 0 then -1 else out
            where out = rdigpow (digits n) p `div` n

rdigpow :: [Integer] -> Integer -> Integer
rdigpow [] p = 0
rdigpow (x:xs) p = x^p + rdigpow xs (p+1)

digits :: Integer -> [Integer]
digits = map (read . return) . show

