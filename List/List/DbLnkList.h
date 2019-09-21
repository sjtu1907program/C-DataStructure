#pragma once
/*
	Doubly linked list
*/
#include <iostream>

namespace DbList_SmartPoint {
	using std::shared_ptr;
	class DbListNode {
	public:
		DbListNode(int x, std::shared_ptr<DbListNode> _pre = nullptr, std::shared_ptr<DbListNode> next = nullptr) : val(x), pre(_pre), next(next) {}

		void SetVal(int v) { val = v; };
		int GetVal() const { return val; }
		void SetNext(std::shared_ptr<DbListNode> n) { next = n; };
		std::shared_ptr<DbListNode> GetNext() const { return next; }
		void SetPre(std::shared_ptr<DbListNode> p) { pre = p; };
		std::shared_ptr<DbListNode> GetPre() const { return pre; }
	private:
		int val;
		std::shared_ptr<DbListNode> pre;
		std::shared_ptr<DbListNode> next;
	};

	class DbLinkList {
	public:
		//functions
		DbLinkList();
		DbLinkList(std::initializer_list<int> l);
		DbLinkList(int v[], int size);
		DbLinkList(const DbLinkList & dbList);
		DbLinkList(DbLinkList&& dbList);
		DbLinkList & operator=(const DbLinkList & dblist);
		DbLinkList & operator=(DbLinkList && dblist);
		~DbLinkList();

		std::shared_ptr<DbListNode> head() const { return m_head; }
		std::shared_ptr<DbListNode> tail() const { return m_tail; }
		int size() const { return m_size; };

		void erase(int x);

		void insert_front(int v);
		void insert_back(int v);
		void insert(shared_ptr<DbListNode> node, int v);
		void clear();
		// return fist node that has value x 
		shared_ptr<DbListNode> find(int x);

	private:
		//members
		std::shared_ptr<DbListNode> m_head{ nullptr };
		std::shared_ptr<DbListNode> m_tail{ nullptr };
		int m_size;
	};

	//���������ע����ڽṹ���Լ�����ⲿ
	std::ostream& operator<<(std::ostream&, DbLinkList&);
}

namespace myClassLibrary {
	class DbListNode {
	public:
		DbListNode(int x, DbListNode * _pre = nullptr, DbListNode * next = nullptr) : val(x), pre(_pre), next(next) {}

		void SetVal(int v) { val = v; };
		int GetVal() const { return val; }
		void SetNext(DbListNode * n) { next = n; };
		DbListNode * GetNext() const { return next; }
		void SetPre(DbListNode * p) { pre = p; };
		DbListNode * GetPre() const { return pre; }
	private:
		int val;
		DbListNode * pre;
		DbListNode * next;
	};

	class DbLinkList {
	public :
		//functions
		DbLinkList();
		DbLinkList(std::initializer_list<int> l);
		DbLinkList(int v[], int size);
		DbLinkList(const DbLinkList & dbList);
		DbLinkList(DbLinkList&& dbList);
		DbLinkList & operator=(const DbLinkList & dblist);
		DbLinkList & operator=(DbLinkList && dblist);
		~DbLinkList();

		DbListNode * head() const { return m_head; }
		DbListNode * tail() const { return m_tail; }
		int size() const { return m_size; };

		void erase(int x);

		void insert_front(int v);
		void insert_back(int v);
		void insert(DbListNode* node, int v);
		void clear();
		// return fist node that has value x 
		DbListNode* find(int x);

	private:
		//members
		DbListNode* m_head{ nullptr };
		DbListNode* m_tail{ nullptr };
		int m_size;
	};

	//���������ע����ڽṹ���Լ�����ⲿ
	std::ostream& operator<<(std::ostream&, DbLinkList&);
}

namespace myStructLibrary {

	struct DbListNode {
		int val;
		DbListNode *pre;
		DbListNode *next;
		DbListNode(int x, DbListNode * _pre = nullptr, DbListNode * next = nullptr) : val(x), pre(_pre), next(next) {}
	};

	struct DbLinkList {
		//members
		DbListNode* m_head{ nullptr };
		DbListNode* m_tail{ nullptr };
		int m_size;

		//functions
		DbLinkList(int v[], int size);

		~DbLinkList();

		int size();

		void erase(int x);

		void insert_front(int v);
		void insert_back(int v);
		void insert(DbListNode* node, int v);

		// return fist node that has value x 
		DbListNode* find(int x);
	};

	//���������ע����ڽṹ���Լ�����ⲿ
	std::ostream& operator<<(std::ostream&, const DbLinkList&);
}