import java.util.Arrays;

public class TargetNumber {
    int c = 0;
    public void count(int[] numbers, int target, int present){
        if (numbers.length == 1){
            if (present + numbers[0] == target)
                c++;
            else if (present - numbers[0] == target)
                c++;
        }else {
            count(Arrays.copyOfRange(numbers, 1, numbers.length), target, present + numbers[0]);
            count(Arrays.copyOfRange(numbers, 1, numbers.length), target, present - numbers[0]);
        }
    }
    public int solution(int[] numbers, int target) {
        int answer = 0;
        count(numbers, target, 0);
        answer = c;
        return answer;
    }
}
