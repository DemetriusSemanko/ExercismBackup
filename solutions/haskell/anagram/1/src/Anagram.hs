module Anagram (anagramsFor) where
import Data.List
import Data.Char

anagramsFor :: String -> [String] -> [String]
anagramsFor target candidates = case (target, candidates) of
  (x', [])                                               -> []
  (x', x:xs)
    | map toLower x' == map toLower x                    -> anagramsFor x' xs
    | (sort (map toLower x')) == (sort (map toLower x))  -> x : (anagramsFor x' xs)
    | otherwise                                          -> anagramsFor x' xs


