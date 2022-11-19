class LinkedListStack {
    private:
        Node* first;
    public: 
        LinkedListStack();

        ~LinkedListStack();

        bool isEmpty();

        void push(string text);

        string pop();
};