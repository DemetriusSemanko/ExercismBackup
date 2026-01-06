#[derive(Debug)]
pub struct HighScores {
    scores: Option<Vec<u32>>,
    latest_score: Option<u32>,
}

impl HighScores {
    pub fn new(scores: &[u32]) -> Self {
        let vec_scores = {
            if scores.is_empty() {
                None
            } else {
                Some(scores.to_vec())
            }
        };
        
        let latest_score = {
            if scores.is_empty() {
                None
            } else {
                Some(scores[scores.len() - 1])
            }
        };

        HighScores {
            scores: vec_scores,
            latest_score: latest_score,
        }
    }

    pub fn scores(&self) -> &[u32] {
        match &self.scores {
            None    => &[],
            Some(x) => x.as_slice()
        }
    }

    pub fn latest(&self) -> Option<u32> {
        self.latest_score
    }

    pub fn personal_best(&self) -> Option<u32> {
        if self.scores.is_none() {
            None
        } else {
            let mut temp_vec = self.scores.clone().unwrap();
            temp_vec.sort();
            Some(
                temp_vec[temp_vec.len() - 1]
            )
        }
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        let mut temp_vec: Vec<u32> = Vec::new();
        if self.scores.is_none() {
            temp_vec
        } else {
            temp_vec = self.scores.clone().unwrap();
            temp_vec.sort_by(|a, b| b.cmp(a));
            while temp_vec.len() > 3 {
                temp_vec.pop();
            }
            temp_vec
        }
    }
}
