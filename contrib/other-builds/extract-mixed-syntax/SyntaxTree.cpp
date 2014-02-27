#include "SyntaxTree.h"

void SyntaxTree::Add(int startPos, int endPos, const std::string &label)
{
	Range range(startPos, endPos);
	Labels &labels = m_coll[range];
	labels.push_back(label);
}

const SyntaxTree::Labels &SyntaxTree::Find(int startPos, int endPos) const
{
	Coll::const_iterator iter;
	iter = m_coll.find(Range(startPos, endPos));
	return (iter == m_coll.end()) ? m_defaultLabels : iter->second;
}
