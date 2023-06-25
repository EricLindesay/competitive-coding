class Cons:
    def __init__(self, head, tail):
        self.head = head
        self.tail = tail
      
    def to_array(self):
        return [self.head] + (self.tail.to_array() if self.tail is not None else [])
      
    @classmethod
    def from_array(cls, arr):
        if not arr:
            return None

        to_return = Cons(arr[0], Cons.from_array(arr[1:]))

        return to_return
    
    def filter(self, fn):
        temp = self
        arr = []
        while temp:
            if fn(temp.head):
                arr.append(temp.head)
            temp = temp.tail 

        return Cons.from_array(arr)

    def map(self, fn):
        temp = self
        while temp:
            temp.head = fn(temp.head)
            temp = temp.tail
        
        return self
