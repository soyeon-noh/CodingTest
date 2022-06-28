function solution(lottos, win_nums) {
  let correctCount = 0;
  let incorrectCount = 0;

  for (let i in lottos) {
    // 지워진 번호 제외
    if (lottos[i] == 0) {
      continue;
    }

    let count = 0;
    for (let j in win_nums) {
      // 당첨인 번호 -> 최저순위
      if (lottos[i] == win_nums[j]) {
        count++;
        continue;
        // 당첨이 아닌 번호 -> 최고순위
      }
    }
    if (count) {
      correctCount++;
    } else {
      incorrectCount++;
    }
  }

  // console.log(incorrectCount, correctCount);

  let max;
  if (incorrectCount < 5) {
    max = incorrectCount + 1;
  } else {
    max = 6;
  }

  let min;
  if (correctCount > 1) {
    min = 7 - correctCount;
  } else {
    min = 6;
  }

  var answer = [max, min];
  // console.log(answer);
  return answer;
}
