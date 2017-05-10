#include "carinfo.h"

CarInfo::CarInfo( )
{
    setYue("0.000");
    setFloatYue(0);
    setChepaihao("******");
    setCheqing("****");
    setChexing("****");
    setChikaren("****");
    setIntKazhong(0);                         // 0是临时卡， 1是月票卡， 2是年卡， 3是VIP卡
    setKazhong("******");                       // 改这个的时候注意上面对应的数字 2是年卡
    setKahao("*******");
    isIn = false;
}
CarStation::CarStation(){

    this->jiluhao = "1";
    this->shoufeizhan = "科院收费站";
    this->chedao = "01";
    this->shoufeiyuan = "肖端伍";
    this->chewei = "100";
    this->int_cheWei = 100;
}

void CarInfo::setYue(QString yue) {
    this->yue = yue;
}

void CarInfo::setKazhong(QString kazhong){
    this->kazhong = kazhong;
}

void CarInfo::setKahao(QString kahao){
    this->kahao = kahao;
}

void CarInfo::setChikaren(QString strs) {
    this->chikaren = strs;
}
void CarInfo::setChexing(QString chexing) {
    this->chexing = chexing;
}
void CarInfo::setCheqing(QString cheqing) {
    this->cheqing = cheqing;
}

void CarInfo::setChepaihao( QString chepaihao ){
    this->chepaihao = chepaihao;
}
void CarInfo::setFloatYue(float f) {
    this->f_yu_e = f;
}
void CarInfo::setIntKazhong(int kazhong){
    this->int_kazhong = kazhong;
}
void CarInfo::setTimeInhour(int timeinhour) {
    this->timeinhour = timeinhour;
}

void CarInfo::setTimeInmm(int timeinmm) {
    this->timeinmm = timeinmm;
}

void CarInfo::setTimeOuthour(int timeouthour) {
    this->timeouthour = timeouthour;
}
void CarInfo::setTimeOutmm(int timeoutmm) {
    this->timeoutmm = timeoutmm;
}

int CarInfo::getTimeInhour(void){
    return this->timeinhour;
}
int CarInfo::getTimeInmm(void){
    return this->timeinmm;
}
int CarInfo::getTimeOuthour(void){
    return this->timeouthour;
}
int CarInfo::getTimeOutmm(void){
    return this->timeoutmm;
}

int CarInfo::getIntKazhong(void) {
    return this->int_kazhong;
}
QString CarInfo::getChikaren(void) {
    return this->chikaren;
}

QString CarInfo::getKahao(void){
    return this->kahao;
}
QString CarInfo::getKazhong(void) {
    return this->kazhong;
}
QString CarStation::getKoufei(void){
    return this->koufei;
}
QString CarInfo::getYue( void ) {
    return this->yue;
}
QString CarInfo::getChepaihao( void ) {
    return this->chepaihao;
}
QString CarInfo::getChexing(void) {
    return this->chexing;
}


QString CarInfo::getCheqing( void ) {
    return this->cheqing;
}


float CarInfo::getFloatYue( void ) {
    return this->f_yu_e;
}


QString CarStation::getShoufeiyuan( void ) {
    return this->shoufeiyuan;
}
QString CarStation::getJiluhao(void){
    return this->jiluhao;
}
QString CarStation::getShoufeizhan( void ) {
    return this->shoufeizhan;
}
QString CarStation::getChewei( void ) {
    return this->chewei;
}
int CarStation::getIntChewei( void  ) {
    return this->int_cheWei;
}
QString CarStation::getChedao( void ){
    return this->chedao;
}
float CarStation::getFloatKoufei( void ) {
    return this->float_koufei;
}
void CarStation::setChewei(QString chewei) {
    this->chewei = chewei;
}
void CarStation::setChedao( QString chedao ) {
    this->chedao = chedao;
}
void CarStation::setShoufeizhan(QString shoufeizhan){
    this->shoufeizhan = shoufeizhan;
}

void CarStation::setShoufeiyuan(QString shoufeiyuan){
    this->shoufeiyuan = shoufeiyuan;
}
void CarStation::setKoufei(QString koufei){
    this->koufei = koufei;
}
void CarStation::setJiluhao(QString jiluhao) {
    this->jiluhao = jiluhao;
}
void CarStation::setFloatKoufei(float kf) {
    this->float_koufei = kf;
}

void CarStation::setIntChewei(int chewei) {
    this->int_cheWei = chewei;
}
