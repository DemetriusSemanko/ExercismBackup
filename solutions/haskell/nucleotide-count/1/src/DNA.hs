module DNA (nucleotideCounts, Nucleotide(..)) where

import Data.Map (Map, fromList, insertWith)

data Nucleotide = A | C | G | T deriving (Eq, Ord, Show)

nucleotideCounts :: String -> Either String (Map Nucleotide Int)
nucleotideCounts xs
  | all (\x -> elem x "ACGT") xs    = Right (nucleotideInsertion xs newNucleotideMap)
  | otherwise                       = Left ("error")
  
newNucleotideMap :: (Map Nucleotide Int)
newNucleotideMap = fromList [(A, 0), (C, 0), (G, 0), (T, 0)]

nucleotideInsertion :: String -> (Map Nucleotide Int) -> (Map Nucleotide Int)
nucleotideInsertion "" x           = x
nucleotideInsertion (x:xs) old_map = nucleotideInsertion xs (insertWith (+) (charToNucleotide x) 1 old_map)


charToNucleotide :: Char -> Nucleotide
charToNucleotide x
  | x == 'A'  = A
  | x == 'C'  = C
  | x == 'G'  = G
  | x == 'T'  = T
  | otherwise = A