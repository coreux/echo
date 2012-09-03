## Copyright 2012 Mo McRoberts.
##
##  Licensed under the Apache License, Version 2.0 (the "License");
##  you may not use this file except in compliance with the License.
##  You may obtain a copy of the License at
##
##      http://www.apache.org/licenses/LICENSE-2.0
##
##  Unless required by applicable law or agreed to in writing, software
##  distributed under the License is distributed on an "AS IS" BASIS,
##  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
##  See the License for the specific language governing permissions and
##  limitations under the License.

bin_PROGRAMS = echo

doc_DATA = LICENSE-2.0

echo_SOURCES = echo.c

dist_man1_MANS = echo.1

if BUILD_DOCS

echo.1: echo.xml
	xsltproc -nonet \
		-param man.charmap.use.subset 0 \
		-param make.year.ranges 1 \
		-param make.single.year.ranges 1 \
		-param man.authors.section.enabled 0 \
		-param man.copyright.section.enabled 0 \
		http://docbook.sourceforge.net/release/xsl-ns/current/manpages/docbook.xsl \
		 $<

endif