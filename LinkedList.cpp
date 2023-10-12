#include "Node.cpp"
template <class T>
class LinkedList
{
	public:
        /**
         * Constructor
         */
		LinkedList()
		{
			m_head = 0;
			m_tail = 0;
			m_size = 0;
		}
        /**
         * Destructor
         */
		~LinkedList()
		{
			delete m_head;
		}
        /**
         * Inserts new node at end of list
         * @param data
         */
		void add(T data)
		{
			Node<T>* newNode = new Node<T>(data);

			if (m_head == 0)
			{
				m_head = m_tail = newNode;
				m_size++;
			}
			else
			{
				m_tail->setNext(newNode);
				m_tail = m_tail->getNext();
				m_size++;
			}
		}
        /**
         * Searches list for a particular index
         * @param index index of node to be found
         * @return pointer to node index
         */
		Node<T>* findNodeByIndex(int index)
		{
			Node<T>* currentNode = m_head;

			for (int i = 0; i < index; ++i)
			{
				if (currentNode->getNext() != 0)
				{
					currentNode = currentNode->getNext();
				}
			}

			return currentNode;
		}
        /**
         * Searches list for a particular value
         * @param value value to be found
         * @return pointer to node with given value
         */
		Node<T>* findNodeByValue(T value)
		{
            Node<T>* current = m_head;
            while (current->getNext() != 0) {
                if (current->getData() == value)
                    return current;
                current = current->getNext();
            }

		}
        /**
         * returns value of node at given index
         * @param index
         * @return value of node
         */
		T getByIndex(int index)
		{
			return findNodeByIndex(index)->getData();
		}

        /**
         * removes a node a certain index
         * @param index index to be removed
         */
		void deleteByIndex(int index)
		{
			Node<T>* precedingNode = findNodeByIndex(index - 1);
			
			
			if (index == m_size)
			{
				precedingNode->setNext(0);
				m_tail = precedingNode;
			}
			else if (index > 0)
			{
				precedingNode->setNext(precedingNode->getNext()->getNext());
			}
			else
			{
				m_head = m_head->getNext();
			}

			m_size--;
		}
        /**
         * Removes node with given value
         * @param value value to be removed
         */
		void deleteByValue(T value) {
            Node<T> *temp = findNodeByValue(value);
            while (m_head->getNext()->getData() != value) {
                m_head = m_head->getNext();
            }
            temp = m_head->getNext();
            m_head->setNext(temp->getNext());
            m_size--;
		}
        /**
         * Gets the size of the node.
         * @return size of node.
         */
		int getSize()
		{
			return m_size;
		}

	private:
		Node<T>* m_head;
		Node<T>* m_tail;

		int m_size;
};