module Pangram (isPangram) where

import Data.Char

isPangram :: String -> Bool
isPangram text = length (go (map toLower (filter isAscii (filter isAlpha text))) []) == 26
  where
    go :: String -> [Char] -> [Char]
    go text acc
      | null text = acc
      | (not (elem (head text) acc)) = go (tail text) ((head text):acc)
      | otherwise                    = go (tail text) acc