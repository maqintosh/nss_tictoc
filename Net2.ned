//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package MCtictoc;

//
// TODO auto-generated type
//
simple Node
{
    parameters:
        double time_interval;
        int destination_address;
    gates:
        input in;
        output out;
}

network Net2
{
    parameters:
        int n_nodes;
        @display("bgb=564,264");
    submodules:
        hub: Hub {
            
        }
        node[n_nodes]: Node {
           
        }
    connections:
        for i=0..n_nodes-1 {
            node[i].out --> hub.in++;
            hub.out++ --> node[i].in;
        }
}
