module Strain (keep, discard) where

discard :: (a -> Bool) -> [a] -> [a]
discard p (x:xs)
  | not (p x)    = x : (discard p xs)
  | otherwise    = discard p xs
discard p []     = []

keep :: (a -> Bool) -> [a] -> [a]
keep p xs = filter p xs
