// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(Debug)]
pub struct Duration {
    duration: f64,
}

impl From<u64> for Duration {
    fn from(s: u64) -> Self {
        let x = s as f64;
        Duration {
            duration: x,
        }
    }
}

pub trait Planet {
    const DURATION: f64;
    
    fn years_during(d: &Duration) -> f64 {
        d.duration * (1f64 / 31_557_600f64) * (1f64 / Self::DURATION)
    }
}

pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

impl Planet for Mercury {
    const DURATION: f64 = 0.2408467;
}
impl Planet for Venus {
    const DURATION: f64 = 0.61519726;
}
impl Planet for Earth {
    const DURATION: f64 = 1.0;
}
impl Planet for Mars {
    const DURATION: f64 = 1.8808158;
}
impl Planet for Jupiter {
    const DURATION: f64 = 11.862615;
}
impl Planet for Saturn {
    const DURATION: f64 = 29.447498;
}
impl Planet for Uranus {
    const DURATION: f64 = 84.016846;
}
impl Planet for Neptune {
    const DURATION: f64 = 164.79132;
}
