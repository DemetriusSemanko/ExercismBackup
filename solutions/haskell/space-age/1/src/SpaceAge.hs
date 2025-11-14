module SpaceAge (Planet(..), ageOn) where

data Planet = Mercury
            | Venus
            | Earth
            | Mars
            | Jupiter
            | Saturn
            | Uranus
            | Neptune

ageOn :: Planet -> Float -> Float
ageOn planet seconds = case (planet, toEarthYears seconds) of
  (Mercury, x) -> (x / 0.2408467)
  (Venus, x) -> (x / 0.61519726)
  (Earth, x) -> x
  (Mars, x) -> (x / 1.8808158)
  (Jupiter, x) -> (x / 11.862615)
  (Saturn, x) -> (x / 29.447498)
  (Uranus, x) -> (x / 84.016846)
  (Neptune, x) -> (x / 164.79132)

toEarthYears :: Float -> Float
toEarthYears = (*) (1.0 / 31557600.0) -- L + ratio
