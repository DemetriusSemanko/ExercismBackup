module Pangram (isPangram) where

import Data.Char

isPangram :: String -> Bool
isPangram text = length (go (map toLower (filter (\x -> (isAlpha x && isAscii x)) text)) []) == 26
  where
    go :: String -> [Char] -> [Char]
    go ([]) acc = acc
    go (x:xs) acc
      | not (elem x acc) = go xs (x:acc)
      | otherwise        = go xs acc