module Bob (responseFor) where

import Data.Char

responseFor :: String -> String
responseFor x
  | isQuestion x && isYelling x = "Calm down, I know what I'm doing!"
  | isQuestion x                = "Sure."
  | isYelling x                 = "Whoa, chill out!"
  | isSilent x                  = "Fine. Be that way!"
  | otherwise                   = "Whatever."

isQuestion :: String -> Bool
isQuestion x = (elem '?' x) && (last (filter (\x -> not (isSpace x)) x) == '?')

isYelling :: String -> Bool
isYelling x = (not (null (filter isAlpha x))) && (and (map isUpper (filter isAlpha x)))

isSilent :: String -> Bool
isSilent x = and (map isSpace x)