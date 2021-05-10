class FixConvert:
    	def __init__(self, init_size):
		self.top = -1
		self.n = init_size
		self.a = []
		self.ans = []
		self.ops_pre = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
	
	def is_empty(self):
		return True if self.top == -1 else False
	
	def peek(self):
		return self.a[-1]
	
	def pop(self):
		if not self.is_empty():
			self.top -= 1
			return self.a.pop()
		else:
			return "$"
	
	def push(self, op):
		self.top += 1
		self.a.append(op)

	def is_operand(self, ch):
		return 'a' <= ch <= 'z' or 'A' <= ch <= 'Z'

	def not_greater(self, i):
		try:
			a = self.ops_pre[i]
			b = self.ops_pre[self.peek()]
			return True if a <= b else False
		except KeyError:
			return False
			
	def in_to_pre(self, exp):
		for i in exp:
			if self.is_operand(i):
				self.ans.append(i)
			
			elif i == '(':
				self.push(i)

			elif i == ')':
				while( (not self.is_empty()) and
								self.peek() != '('):
					a = self.pop()
					self.ans.append(a)
				if (not self.is_empty() and self.peek() != '('):
					return -1
				else:
					self.pop()

			else:
				while(not self.is_empty() and self.not_greater(i)):
					self.ans.append(self.pop())
				self.push(i)

		while not self.is_empty():
			self.ans.append(self.pop())

		print("".join(self.ans))

s = input()
the = FixConvert(len(s))
the.in_to_pre(s)
