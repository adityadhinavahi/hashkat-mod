/*void output_position(Network& network) {
    static const int OUTPUT_THRESHOLD = 10000;
    int n_agents = network.size();
    ofstream output1;
    output1.open("output/network.gexf");
    output1 << "<gexf version=\"1.2\">\n"
            << "<meta lastmodifieddate=\"2019-11-09\">\n"
            << "<creator> Dhinavahi Aditya </creator>\n"
            << "<description> Dynamic Social Network Visualization </description>\n"
            << "</meta>\n"
            << "<graph mode=\"dynamic\" defaultedgetype=\"directed\">\n"
            << "<nodes>\n";
}*/
struct Node{
    int id;
    int label;
    int timestamp;
    int score[2];

};
//in step_analysis function
ofstream output1;
output1.open("output/nodes.dat","a");
n_agents = network.size()
Node n = malloc(n_agents * sizeof(Node));
for (int i = 0;i < n_agents;i++){ 
            &p = network[i];
            *(n+i).id -> i;
            *(n+i).label -> p.agent_type;
            *(n+i).timestamp -> time;
            *(n+i).score[0] -> time;
            *(n+i).score[1] -> 0; //For time being assume score is 0
            fwrite(n,sizeof(Node),1,output1);
        }
free(n);
output1.close();

//in io.cpp
void output_position(Network& network) {
    static const int OUTPUT_THRESHOLD = 10000;
    int n_agents = network.size();
    ofstream output1;
    output1.open("output/network.gexf");
    output1 << "<gexf version=\"1.3\">\n"
            << "<meta lastmodifieddate=\"2019-11-12\">\n"
            << "<creator> Dhinavahi Aditya </creator>\n"
            << "<description> Social Network Visualization </description>\n"
            << "</meta>\n"
            << "<graph defaultedgetype=\"directed\" timeformat=\"double\" timerepresentation=\"timestamp\" mode=\"dynamic\">\n"  //"<graph mode=\"dynamic\" defaultedgetype=\"directed\">\n"
            << "<attributes class=\"node\" mode=\"dynamic\">"
            << "<attribute id=\"score\" title=\"score\" type=\"integer\"></attribute>\n"
            << "</attributes>\n"
            << "<nodes>\n";
    int count = 0;
    // Only output position for small networks:
    if (n_agents <= OUTPUT_THRESHOLD) {
        for (int i = 0; i < n_agents; i++) {
                fstream output2('nodes.dat',ios::binary);
                Node n;
                output1 << "<node id=\"" << i << "\" label=\"" << p.agent_type << "\" >\n";
                output1 << "<spells>\n";
                while (fread(&n, sizeof(Node), 1, output2)){
                    if (n.id == i) {
                        output1 << "<spell timestamp=\"" << n.timestamp << "\"></spell>\n";
                    }
                }
                output1 << "</spell>\n";
                output1<< "<attvalues>\n";
                output2.close();
                fstream output('nodes.dat',ios::binary);
                while(fread(&n,sizeof(Node),1,output)){
                    if(n.id == i){
                        output << "<attvalue for=\"score\" value=\""<<n.score[1]<< "\"timestamp=\""<<n.timestamp<<"\"></attvalue>";
                    }
                }
                output << "<attvalues>\n";
                output.close();
        }
        output1 << "</nodes>\n" << "<edges>\n";
        for (int id = 0; id < n_agents; id++) {
            for (int id_fol : network.following_set(id).as_vector()) {
                output1 << "<edge id=\"" << count << "\" source=\"" << id
                        << "\" target=\"" << id_fol << "\"/>\n";
                count++;
            }
        }
        output1 << "</edges>\n" << "</graph>\n" << "</gexf>";
        output1.close();
}
