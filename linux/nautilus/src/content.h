/**
 * Copyright (c) 2000-2012 Liferay, Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 */ 
#ifndef __CONTENT_H__
#define __CONTENT_H__

#include <map>
#include <set>
#include <string>

class ContentManager
{
public:
	static ContentManager& instance();

	std::string getFileIconName(const std::string& fileName) const;

	void setIconForFile(const std::string& fileName, int icon);
	void removeFileIcon(const std::string& fileName);
	int registerIcon(const std::string& fileName);
	void unregisterIcon(int iconId);

	void enableOverlays(bool enable);
	bool isOverlaysEnabled();

	void setMenuTitle(const std::string& title);
	const std::string& getMenuTitle() const;
private:
	std::map<std::string, int> iconsForFiles_;
	int lastIconId_;
	std::map<int, std::string> icons_;

	bool overlaysEnabled_;
	std::string menuTitle_;
	mutable std::set<std::string> registeredFolders_;
	
	ContentManager();
	~ContentManager();
};

#endif
