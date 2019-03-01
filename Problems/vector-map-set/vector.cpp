	vector<long long> num;
	long long count;
	int n=0;
	do{
		cin>>count;
		num.push_back(count);
		n++;//计数个数
	}while(cin.get()!='\n');// 动态输入
	cout<<num.size()<<endl; // 输出向量大小
	cout<<num.front()<<endl; // 输出第一个
	num.pop_back(); // 弹出最上面的一个
	for(vector<long long>::iterator t=num.begin();t<num.end();t++){// 顺序输出 
		cout<<*t<<endl;
	}


	