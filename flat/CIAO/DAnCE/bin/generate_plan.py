#!/usr/bin/python

def parse_args ():
    from optparse import OptionParser

    parser = OptionParser ("""usage %prog [options]
    Note that this script is very simple.  It assumes that the idl and mpc follow
    canonical and predictable patterns.""")

    parser.add_option ("-o", "--output", dest="output", action="store", type="string",
                       help="Output filename", default="Plan.cdp")
    parser.add_option ("--home", dest="homes", action="append", type="string",
                       help="Home types to be included")
    parser.add_option ("-c", "--component", dest="components", action="append",
                       type="string", help="Component types to be included")
    parser.add_option ("--homed-component", dest="homed_components", action="append",
                       type="string", help="Homed component types to be included")
    parser.add_option ("-u", "--uuid", dest="uuid", action="store",
                       type="string", help="UUID for the generated plan")
    
    (options, arguments) = parser.parse_args ()

    return (options, arguments)

def main ():
    (opts, args) = parse_args ()

    # compset = set (opts.homes) | set (opts.components) | set (homed_components)

    from PythonDAnCE import generator
    retval = ""
    retval += generator.header.template (opts.uuid)

    artifacts = {}

    #implementations
    
    for item in opts.homes:
        retval += generator.home_impl.template (item)
        artifacts[item] = 1

    for item in opts.homed_components:
        retval += generator.homed_comp_impl.template (item)
        artifacts[item] = 1

    for item in opts.components:
        retval += generator.comp_impl.template (item)
        artifacts[item] = 1

    #instances
    for item in opts.homes:
        retval += generator.home_inst.template (item)

    for item in opts.homed_components:
        retval += generator.homed_comp_inst.template (item)

    for item in opts.components:
        retval += generator.comp_inst.template (item)
        
    #artifacts
    for item in artifacts.keys():
        retval += generator.artifact.template(item)

    retval += generator.footer.template ()
    
    outfile = open (opts.output, 'w')
    outfile.write (retval)
    outfile.close ()
    

if __name__ == "__main__":
    main ()

    
    
