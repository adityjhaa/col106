run: tester.out
	@./tester.out

tester.out: tester.cpp qna_tool.cpp Node.cpp
	@g++ tester.cpp qna_tool.cpp Node.cpp -o tester.out

clean:
	@rm tester.out