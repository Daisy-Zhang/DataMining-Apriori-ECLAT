该目录下包含：
1. 算法的具体实现文件Apriori.cpp & Apriori.h，Eclat.cpp & Eclat.h
2. 主函数文件：main.cpp
3. 编译链接文件：makefile
4. 所提供的数据集文件：data.txt

运行方式：
测试通过环境：Mac(or Ubuntu)
1. 执行命令：make。之后该目录下会生成命名为 hw3 的可执行文件
2. 保证数据集 data.txt 和可执行文件 hw3 在同一目录下，执行：./hw3
3. 在输出信息 “Transaction read done” 之后，输入自定义的最小支持度：min_sup
4. 之后可以看到两个算法输出结果信息，具体的输出指标涵义见上层目录的report