
# IEEECheckin
*by X4n4th*

### NOTICE
Currently in development.
Client still lacks some features and might have some serious bugs.

**Tested to build on**

 * Windows (VS2010) windows specific :/

### Features

 * Easy to use Electronic attendance system using swipe cards
 * Export mySQL database data to excel

### Configuration Notes

**MYSQL Database:**
	* TABLE: checkin
	* STRUCTURE
		* Email Address - Student Email Address (varchar, primary Key
		* studentID      - student number from ID card (varchar)
		* accessID      - human-readable owner of card (varchar)
		* points         - the number of points (int)
		* time          - the time of last check-in (timestamp)


### Bug tracker

Here is the [bug tracker](https://github.com/x4n4th/IEEECheckin/issues).


### Compiling

IEEECheckin requires the following libraries:

 * [BOOST 1.49](http://www.boost.org/)
 * [mysql 5.5.16](http://www.mysql.com/downloads/mysql/)
 * [Qt](http://qt.nokia.com/products/)

**Compiling using Windows (VS2010)

 * Download and compile QT
 * Install Qt
 * Download and compile [Boost](http://www.boost.org/)
 * Add Boost libraries to project
 * Download and Install MYSQL community with developer tools
 * Add MYSQL libraries to project
 * Build
 * Run IEEECheckin.exe
