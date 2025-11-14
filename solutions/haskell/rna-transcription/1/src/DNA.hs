module DNA (toRNA) where

toRNA :: String -> Either Char String
toRNA xs = case (xs, [ x | x <- xs, (not (elem x ['G', 'C', 'T', 'A']))]) of
  (xs, [])      -> (Right (map transcribe xs))
  (_, filtered) -> (Left (head filtered)) 
  where
    transcribe :: Char -> Char
    transcribe x
      | (x == 'G') = 'C'
      | (x == 'C') = 'G'
      | (x == 'T') = 'A'
      | (x == 'A') = 'U'
      | otherwise  = x
