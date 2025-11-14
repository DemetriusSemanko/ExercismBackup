module Darts (score) where

score :: Float -> Float -> Int
score x y
  | dist > 10 = 0
  | dist <= 10 && dist > 5 = 1
  | dist <= 5 && dist > 1 = 5
  | otherwise = 10
    where
    dist = sqrt (((x - 0) ^ 2) + ((y - 0) ^ 2))