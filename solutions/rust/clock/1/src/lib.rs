use std::fmt;

#[derive (Eq, PartialEq, Debug)]
pub struct Clock {
    minutes: i32,
}

impl Clock {
    pub fn new(hours: i32, minutes: i32) -> Self {
        Self {
            minutes: (hours * 60 + minutes).rem_euclid(1440),
        }
    }

    pub fn add_minutes(&self, minutes: i32) -> Self {
        Self::new(0, self.minutes + minutes)
    }

    pub fn hours(&self) -> i32 {
        self.minutes / 60
    }
}

impl fmt::Display for Clock {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let time_format = |x: i32| -> String {
            format!("{}", if x < 10 { "0".to_string() + &x.to_string() } else { x.to_string() })
        };
        
        write!(f, "{}:{}", time_format(self.hours()), time_format(self.minutes % 60))
    }
}