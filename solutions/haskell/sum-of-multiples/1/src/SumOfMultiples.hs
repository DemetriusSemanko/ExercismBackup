module SumOfMultiples (sumOfMultiples) where

sumOfMultiples :: [Integer] -> Integer -> Integer
sumOfMultiples factors limit = go factors limit []
  where go :: [Integer] -> Integer -> [Integer] -> Integer
        go facs lim mults = case (facs, lim, mults) of
          ([], _, [])        -> 0
          ([], _, mults)     -> sum mults
          (0:xs, lim, mults) -> go xs lim (mults ++ if (elem 0 mults) then [] else [0])
          (x:xs, lim, mults) -> go xs lim (mults ++ [y | y <- [x, (x + x)..(lim - 1)], not (elem y mults)])
