input_list = [")))()", ")(()"]

def problem2(input):
    # 이 곳에 코드를 작성하세요.
    open_needed = 0
    close_needed = 0

    for char in input:
        if char == '(':
            open_needed += 1
        else:  # char == ')'
            if open_needed > 0:
                open_needed -= 1
            else:
                close_needed += 1

    result = open_needed + close_needed
    return result

# 각각의 입력에 대해 문제 풀이 실행
for i, input_str in enumerate(input_list):
    result = problem2(input_str)
    print(f"입력 {i+1}: {input_str} → 출력: {result}")
    assert result == [3, 2][i]

print("정답입니다.")
