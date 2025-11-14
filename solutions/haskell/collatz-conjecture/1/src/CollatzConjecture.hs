module CollatzConjecture (collatz) where

collatz :: Integer -> Maybe Integer
collatz n = go n n 0
  where go :: Integer -> Integer -> Integer -> Maybe Integer
        go n original steps
          | (n < 1)                         = Nothing
          | (n == original) && (steps /= 0) = Nothing
          | (n == 1)                        = Just steps
          | (even n)                        = go (div n 2) original (steps + 1)
          | otherwise                       = go ((n * 3) + 1) original (steps + 1)
